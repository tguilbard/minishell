; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/01/31 08:04:09 by ldutriez          #+#    #+#              ;
;    Updated: 2020/02/05 11:59:36 by ldutriez         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcpy
extern _ft_strlen
_ft_strcpy:
init:
	mov		rcx, 0
	cmp		rdi, 0
	jz		error
	cmp		rsi, 0
	jz		error
loop:
	mov		dl, [rsi + rcx]
	mov		[rdi + rcx], dl
	inc		rcx
	cmp		dl, 0
	jnz		loop
end:
	mov rax, rdi
	ret
error:
	mov rax, 0
	ret
