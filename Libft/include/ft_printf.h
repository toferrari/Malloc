/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:37:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/25 13:48:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

typedef	struct	s_struct
{
	int			bool_acc;
	int			accuracy;
	int			htag;
	int			plus;
	int			moins;
	int			zero;
	int			width;
	int			h;
	int			l;
	int			space;
	int			z;
	int			j;
	char		c;
	int			ret;
	int			color;
	char		*tmp;
	wchar_t		chr;
	int			i_tmp;

}				t_print;

int				ft_printf(char *format, ...);
void			ft_init_struct(t_print *s_ptf);
int				ft_parse_flag(char **format, va_list *arg, char **str, int ret);
int				ft_flag_d(t_print ptf, int nb, char **str);
void			ft_strputnchr(char **str, char c, int n);
int				ft_call_arg(va_list *arg, char **str, t_print ptf,
				char **format);
int				ft_convert_signe(char **str, t_print ptf, int nb);
int				ft_flag_lld(t_print ptf, int64_t nb, char **str);
int				ft_flag_u(t_print ptf, unsigned int nb, char **str);
int				ft_flag_llu(t_print ptf, uint64_t nb, char **str);
int				ft_flag_pourcent(t_print ptf, char **str);
int				ft_flag_octal(t_print ptf, unsigned int nb, char **str);
int				ft_flag_hexa(t_print ptf, unsigned int nb, char **str);
int				ft_flag_str(t_print ptf, char *src, char **str);
int				ft_flag_llhexa(t_print ptf, uint64_t nb, char **str);
int				ft_flag_llo(t_print ptf, uint64_t nb, char **str);
int				ft_flag_hd(t_print ptf, int nb, char **str);
int				ft_flag_ho(t_print ptf, unsigned short nb, char **str);
int				ft_flag_chr(t_print ptf, char c, char **str);
int				ft_flag_c_null(t_print ptf, char **format, char **str);
int				ft_flag_p(t_print ptf, uint64_t nb, char **str);
int				ft_flag_hhd(t_print ptf, char nb, char **str);
int				ft_flag_hhu(t_print ptf, unsigned char nb, char **str);
int				ft_flag_hho(t_print ptf, unsigned char nb, char **str);
int				ft_flag_hhx(t_print ptf, unsigned char nb, char **str);
int				ft_flag_wchr(t_print ptf, wchar_t c, char **str);
int				ft_flag_wstr(t_print ptf, wchar_t *src, char **str);
char			*ft_wchar_to_char(wchar_t c, char *dest);
int				ft_flag_color(char **str, t_print *ptf, char **format);
void			ft_flag(char ***format, t_print *s_ptf);
int				ft_flag_b(t_print ptf, unsigned int nb, char **str);

#endif
