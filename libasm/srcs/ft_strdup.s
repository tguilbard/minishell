; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/01/31 08:05:11 by ldutriez          #+#    #+#              ;
;    Updated: 2020/02/05 13:58:59 by ldutriez         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strdup
extern _malloc
extern _ft_strlen
extern _ft_strcpy
_ft_strdup:
	cmp		rdi, 0
	jz		error
	call	_ft_strlen
	inc		rax
	push	rdi
	mov		rdi, rax
	call	_malloc
	cmp		rax, 0
	jz		error
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret
error:
	mov		rax, 0
	ret
