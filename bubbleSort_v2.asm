.code
# s0 = &array + i * 4
# s1 = size - 1
# -------------
# s2 = i
# s3 = isChanged

la $s0, array

la $s1, size
lw $s1, 0($s1)
addi $s1, $s1, -1
	
do:

la $s0, array
add $s3, $0, $0
add $s2, $0, $0
for:

slt $t0, $s2, $s1
beq $t0, $0, end_for
if:

lw $t1, 4($s0)
lw $t2, 0($s0)

slt $t0, $t1, $t2
beq $t0, $0, end_if

sw $t1, 0($s0)
sw $t2, 4($s0)

addi $s3, $0, 1

end_if:
addi $s0, $s0, 4
addi $s2, $s2, 1
j for
end_for:

beq $s3, $0, end_do
j do

end_do:

.data
	array: .word 85, 3, 20, 34, 33, 38, 97, 76, 44, 28, 58, 75, 4, 49, 60, 71, 73, 45, 15, 24, 6, 63, 89, 67, 52, 41, 40, 22, 43, 1
	size : .word 30