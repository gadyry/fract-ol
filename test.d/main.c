/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:42:54 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/17 20:34:48 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // for debuging !
#include "mlx.h" // Inclusion de MiniLibX
#include <stdlib.h> // Pour exit()


#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void *mlx_ptr;   // Pointeur pour l'initialisation de la connexion
void *win_ptr;   // Pointeur pour la fenêtre
int zoom = 1;    // Facteur de zoom

// Fonction pour dessiner un rectangle
void draw_rectangle(void *mlx_ptr, void *win_ptr, int x, int y, int width, int height, int color)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
        }
    }
}

// Fonction pour gérer les événements de la souris (zoom)
int mouse_hook(int button, int x, int y, void *param)
{
    (void)x;  // On ne se sert pas des coordonnées X de la souris dans cet exemple
    (void)y;  // On ne se sert pas des coordonnées Y de la souris dans cet exemple

    if (button == 4)  // Molette de la souris vers le haut (zoom) (zoom in)
        zoom += 1;
    if (button == 5)  // Molette de la souris vers le bas (dézoom) (zoom out)
        zoom -= 1;

    if (zoom < 1)  // Le zoom ne doit pas être négatif ou nul
        zoom = 1;

    // Efface la fenêtre et redessine
    mlx_clear_window(mlx_ptr, win_ptr);
    mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF, "Zoom: ");
    char zoom_text[20];
    sprintf(zoom_text, "%d", zoom);
    mlx_string_put(mlx_ptr, win_ptr, 70, 10, 0xFFFFFF, zoom_text);

    // Redessine un rectangle avec le zoom
    draw_rectangle(mlx_ptr, win_ptr, 200, 200, zoom * 50, zoom * 50, 0x00FF00);

    return (0);
}

// Fonction pour gérer les événements du clavier
int key_hook(int keycode, void *param)
{
    (void)param;  // On ne se sert pas du paramètre ici

    if (keycode == 53)  // La touche 'Esc' pour fermer la fenêtre
    {
        mlx_destroy_window(mlx_ptr, win_ptr);
        exit(0);
    }

    if (keycode == 13)  // Touche 'W' pour changer la couleur du rectangle
    {
        mlx_clear_window(mlx_ptr, win_ptr);
        mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0xFFFFFF, "Zoom: ");
        char zoom_text[20];
        sprintf(zoom_text, "%d", zoom);
        mlx_string_put(mlx_ptr, win_ptr, 70, 10, 0xFFFFFF, zoom_text);

        // Redessine un rectangle rouge avec le zoom
        draw_rectangle(mlx_ptr, win_ptr, 200, 200, zoom * 50, zoom * 50, 0xFF0000);
    }

    return (0);
}

int main()
{
    // Initialisation de la connexion avec MiniLibX
    mlx_ptr = mlx_init();
    if (mlx_ptr == NULL)
        return (1);

    // Créer une fenêtre de 800x600
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Windows !");
    if (win_ptr == NULL)
        return (1);

    // Affiche le texte initial
    mlx_string_put(mlx_ptr, win_ptr, 10, 10, 0x0000FF, "Zoom: 1");
    mlx_string_put(mlx_ptr, win_ptr, 10, 30, 0x0000FF, "Press ESC to Exit");

    // Dessine un rectangle initial
    draw_rectangle(mlx_ptr, win_ptr, 200, 200, zoom * 50, zoom * 50, 0x00FF00); // use mlx_pixel_put

    // Hook pour la molette de la souris (zoom)
    mlx_mouse_hook(win_ptr, mouse_hook, NULL);

    // Hook pour les événements du clavier
    mlx_key_hook(win_ptr, key_hook, NULL);

    // Boucle pour maintenir la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return (0);
}
