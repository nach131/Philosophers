/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:37:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 17:29:00 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET "\x1B[0m"

// # Regular Colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define ORANGE "\033[1;31m"
# define WHITE "\033[0;37m"
# define BLACK "\x1B[30m"

// # Bold
# define BBLACK "\033[1;30m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BMAGENTA "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"
# define BORANGE "\033[1;31m"

// # Italic
# define IRED "\x1B[3m\x1B[31m"
# define IGREEN "\x1B[3m\x1B[32m"
# define IYELLOW "\x1B[3m\x1B[33m"
# define IBLUE "\x1B[3m\x1B[34m"
# define IMAGENTA "\x1B[3m\x1B[35m"
# define ICYAN "\x1B[3m\x1B[36m"
# define IORANGE "\x1B[3m\x1B[38;2;255;165;0m"
# define IWHITE "\x1B[3m\x1B[37m"

// # Underline
# define URED "\x1B[4m\x1B[38;2;230;50;50m"
# define UGREEN "\x1B[4m\x1B[38;2;0;255;0m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\x1B[4m\x1B[38;2;47;82;191m"
# define UMAGENTA "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UORANGE "\x1B[4m\x1B[38;2;255;165;0m"
# define UWHITE "\033[4;37m"

// # UNICODE
# define DHOR "\u2550"
# define LSHADE "\u2591"
# define MSHADE "\u2592"
# define DSHADE "\u2593"
# define FBLOCK "\u2588"
# define EBLOCK "\u258d"
# define FLECHAD "\u2911"

#endif

// DHOR		════════════════════════
// LSHADE	░░░░░░░░░░░░░░░░░░░░░░░░
// MSHADE	▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
// MSHADE	▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
// FBLOCK	████████████████████████
// EBLOCK	▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍▍
// FLECHAD	⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑⤑

// \x1B es la secuencia de escape ANSI.
// [3m activa el formato de texto en cursiva.
// [38;2;255;165;0m establece el color utilizando
// el modelo de color RGB para obtener naranja.
