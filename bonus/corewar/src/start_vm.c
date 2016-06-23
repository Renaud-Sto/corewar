/*
** start_vm.c for corewar in /home/descho_e/year_2015_2016/C_Prog_Elem/coreware
** 
** Made by Eric DESCHODT
** Login   <descho_e@epitech.net>
** 
** Started on  Mon Mar  7 13:35:33 2016 Eric DESCHODT
** Last update Sat Mar 26 11:52:13 2016 Eric DESCHODT
*/

#include "corewar.h"

void            init_alive(t_vm *vm)
{
  int           i;
  t_champ       *tmp;

  tmp = vm->begin;
  i = 0;
  while (i < vm->nb)
    {
      tmp->alive = 0;
      tmp = tmp->next;
      i++;
    }
}

int		execute_champ(t_vm *vm, t_champ *champ,
			      unsigned char board[2][MEM_SIZE])
{
  if (champ->cycle == 0)
    load_instru(vm, champ, board);
  else if (champ->cycle == champ->ope.nbr_cycles)
    champ->cycle = 0;
  else
    champ->cycle++;
  return (0);
}

int		all_champ(t_vm *vm,
			  unsigned char board[2][MEM_SIZE],
			  t_data *data)
{
  int		i;
  t_champ	*tmp;

  elarg_text(data->pix, &data->pos, &data->size, data->back);
  printboardgraph(data->pix, board);
  bunny_blit(&data->win->buffer, &data->pix->clipable, NULL);
  bunny_display(data->win);
  i = 0;
  tmp = vm->begin;
  while (i < vm->nb && tmp != NULL)
    {
      execute_champ(vm, tmp, board);
      tmp = tmp->next;
      i++;
    }
  return (0);
}

int		start_vm(t_vm *vm,
			 unsigned char board[2][MEM_SIZE],
			 t_data *data)
{
  int		end;
  int		start;
  int		var;

  var = 0;
  end = CYCLE_TO_DIE;
  while (end > 0 && vm->nb > 1)
    {
       start = end;
      init_alive(vm);
      while (start > 0)
	{
	  if (vm->dump != 0)
	    var++;
	  all_champ(vm, board, data);
	  start--;
	  if (vm->dump != 0 && vm->dump == var)
	    return (0);
	}
      kill_champ(vm);
      end -= CYCLE_DELTA;
    }
  return (0);
}
