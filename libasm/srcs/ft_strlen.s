; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: ldutriez <ldutriez@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/02/04 13:29:09 by ldutriez          #+#    #+#              ;
;    Updated: 2020/02/05 12:01:26 by ldutriez         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen
_ft_strlen:
	mov		rax, 0
	cmp		rdi, 0
	je		end
	jne		loop
increment :
	inc		rax
loop:
	mov		r8b, BYTE[rdi + rax]
	cmp		r8b, 0
	jne		increment
end:
	ret
