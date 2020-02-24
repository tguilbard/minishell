; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/01/31 08:04:54 by ldutriez          #+#    #+#              ;
;    Updated: 2020/02/05 13:34:42 by ldutriez         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_read
_ft_read:
	mov	rax, 0x2000003
	syscall
	jc	error
	ret
error:
	mov rax, -1
	ret
