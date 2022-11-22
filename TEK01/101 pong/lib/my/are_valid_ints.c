/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-finalstumper-taha-idriss.elakramine
** File description:
** ara_valid_ints
*/

unsigned char are_valid_ints(long x, long y)
{
    if (x < -2147483648 || y < -2147483648)
        return (0);
    else if (x > 2147483647 || y > 2147483647)
        return (0);
    else
        return (1);
}