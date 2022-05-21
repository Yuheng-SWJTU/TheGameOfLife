#ifndef THEGAMEOFLIFE_UTILITIES_H
#define THEGAMEOFLIFE_UTILITIES_H

/**
 * @brief According to the parameter choosing the width of the cell
 *
 * @param temp is the string
 * @param width is the width of the cell
 * @return The string with the width of the cell
 */
char * choose_width(char * temp, int width);

/**
 * @brief Check the input whether contains only 0 and 1
 *
 * @param line is the input
 * @return The result of the line
 */
char * check_init(char * line);

#endif //THEGAMEOFLIFE_UTILITIES_H
