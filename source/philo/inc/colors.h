/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:37:54 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/03/23 16:29:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

// # Regular Colors

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"
# define ORANGE "\033[1;31m"
# define BLACK "\x1B[30m"

// # Bold

# define BBLACK "\033[1;30m"
# define BYELLOW "\033[1;33m"
# define BBLUE "\033[1;34m"
# define BMAGENTA "\033[1;35m"
# define BCYAN "\033[1;36m"
# define BWHITE "\033[1;37m"
# define BORANGE "\033[1;31m"

// # Underline

# define UORANGE "\033[4;31m"
# define UYELLOW "\033[4;33m"
# define UBLUE "\033[4;34m"
# define UMAGENTA "\033[4;35m"
# define UCYAN "\033[4;36m"
# define UWHITE "\033[4;37m"

// # Background
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGYELLOW "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGWHITE "\033[47m"

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
