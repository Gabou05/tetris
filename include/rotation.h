/**
 * @file rotation.h
 * @brief Functions to rotate an object in a matrix
 */

/**
 * @author Gabriel Pitou gabriel.pitou@ecole.ensicaen.fr
 * @version 1.0.0
 * @date 21 Novembre 2025
 */

#ifndef ROTATE_H
#define ROTATE_H

#include <stdio.h>

#define LENGTH 10

/**
 * @brief Display correctly the matrix in stdout
 * 
 * @param The matrix you want to display
 */
void display(int tab[LENGTH][LENGTH]);

/**
 * @brief Rotate a value by the origin in the matrix
 *
 * @param The matrix, the position x and y of the value you want to rotate, the position xo and yo of the origin in the plan, the rotation you want: 1 = 90°, 2 = 180°, 3 = 270°, other = 360°;
 */
void rotation_unite(int tab[LENGTH][LENGTH], int x, int y, int rotation, int origin_x, int origin_y);

/**
 * @brief Rotate an object (defined by all the points which value is 1) in the matrix
 *
 * @param The matrix, the rotation you want;
 */
void rotation(int tab[LENGTH][LENGTH], int rotation,int origin_x,int origin_y);

#endif /* ROTATE_H */ 
