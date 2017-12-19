/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/22 13:47:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_list
{
	const void			*content;
	size_t				content_size;
	struct s_list		*next;
}				t_list;

void			*ft_memset(void *b, int c, size_t size);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *str);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dst, const char *src, unsigned int n);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *litlle);
char			*ft_strnstr(const char *big, const char *little, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(const char *s, char (*f)(char));
char			*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, unsigned int n);
char			*ft_strsub(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int c, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int				ft_intlen(int n);
char			*ft_reverse_nb(char *s);
int				ft_nbword(char *s, char c);
int				*ft_nbletter(char *s, char c, int *nbletter, int nbword);
char			**ft_fill(char **d, char *s, char c, int nbword);
void			ft_putstrnbr(char *str, int nb);
void			ft_putnbrendl(int nb);
char			*ft_realloc_chr(char *src, int size);
int				ft_realloc_adr(char **str, int size);
char			*ft_strnchr(char *src, char *find);
void			ft_strputnchr(char **str, char c, int n);
char			*ft_strccat(char *dest, char *src, char c);
int				ft_strclen(char *str, char c);
char			*ft_strnccat(char *dest, char c, int n);
int				ft_intlen_64(int64_t n);
char			*ft_itoa_64(int64_t n);
char			*ft_strlnccat(char *dest, char c, int *start, int len);
char			*ft_strcat_p(char *dest, const char *src, int len);
int				ft_realloc_adr_p(char **str, int size, int len);
char			*ft_itoa_base(unsigned int nb, int base);
int				ft_intlen_base(unsigned int n, int base);
char			*ft_itoa_base64(uint64_t nb, int base);
int				ft_intlen_base64(uint64_t n, int base);
char			*ft_strupper(char *s);
int				ft_wchar_len(wchar_t c);
char			*ft_wchrcat(char *dest, const char *src, int start, int len);
char			*ft_strccat_p(char *dest, char *src, char c, int start);
char			*ft_strcpy_p(char *dst, const char *src, int len);
int				ft_wstr_len(wchar_t *str);
int				*ft_intmal(int len);
void			ft_swap(int *b, int *a);

#endif
