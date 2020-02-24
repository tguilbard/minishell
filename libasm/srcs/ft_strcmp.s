; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/01/31 08:04:25 by ldutriez          #+#    #+#              ;
;    Updated: 2020/02/05 13:15:45 by ldutriez         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcmp
_ft_strcmp:
	cmp		rdi, 0
	jz		error
	cmp		rsi, 0
	jz		error
	mov		rcx, 0
loop:
	mov		r8b, BYTE[rdi + rcx]
	mov		r9b, BYTE[rsi + rcx]
	cmp		r8b, r9b
	jl		negative
	jg		positive
	cmp		r8b, 0
	je		equal
	inc		rcx
	jmp		loop
equal:
	mov		rax, 0
	ret
negative:
	mov		rax, -1
	ret
positive:
	mov		rax, 1
	ret
error:
	mov		rax, -2
	ret
