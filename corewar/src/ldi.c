/*
** ldi.c for ldi.c in /home/roig_a/COREWAR/coreware
** 
** Made by Antoine Roig
** Login   <roig_a@epitech.net>
** 
** Started on  Wed Mar 23 15:27:28 2016 Antoine Roig
** Last update Wed Mar 23 16:36:24 2016 Antoine Roig
*/

#include "corewar.h"

int	ldi(t_args *arg, void *champ, unsigned char *board)
{
  t_byte	uni;
  t_byte	uni1;
  int		i;

  swap_carry(((t_champ *)champ));
  if (arg[2].val <= 0 || arg[2].val > REG_NUMBER)
    return (0);
  (void)board;
  i = -1;
  uni.full = arg[0].val;
  uni1.full = arg[1].val;
  uni.full = uni.full % IDX_MOD;
  uni.full += uni1.full;
  if (uni.full < 0)
    while (++i < uni.full % IDX_MOD)
      moving_PC(champ, board, -1);
  else
    while (++i < uni.full % IDX_MOD)
      moving_PC(champ, board, 1);
  ((t_champ *)champ)->reg[arg[2].val - 1][0] = uni.byte[0];
  ((t_champ *)champ)->reg[arg[2].val - 1][1] = uni.byte[1];
  ((t_champ *)champ)->reg[arg[2].val - 1][2] = uni.byte[2];
  ((t_champ *)champ)->reg[arg[2].val - 1][3] = uni.byte[3];
  return (0);
}
