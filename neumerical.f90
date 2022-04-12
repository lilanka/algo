!Add binary numbers 
PROGRAM AddBinaryIntegers
  INTEGER :: n, i, A_SUM, B_SUM, TOT 
  INTEGER(KIND= 2), DIMENSION(5) :: A, B, C  !2 bytes
  
  n = 5       !Dimension of the array
  A_SUM = 0   !Sum of array A
  B_SUM = 0   !Sum of array B
  A = (/0, 0, 1, 1, 1/)
  B = (/0, 1, 0, 0, 0/)
  
  DO i = 1, n
    A_SUM = A_SUM + A(n+1-i) * 2**i
    B_SUM = B_SUM + B(n+1-i) * 2**i
  END DO   
 
  TOT = A_SUM + B_SUM
  CALL ConvertDecimalToBinary(TOT, n, C) 
  PRINT *, C
END PROGRAM AddBinaryIntegers

!Convert decimal values to binary
SUBROUTINE ConvertDecimalToBinary(a, n, C) 
  INTEGER :: a, temp, i
  INTEGER(KIND= 2), DIMENSION(5) :: C 

  temp = a
  DO i = 1, n
    C(n+1-i) = MOD(temp, 2)
    temp = temp / 2
  END DO
END SUBROUTINE ConvertDecimalToBinary 

!Just for debugging 
SUBROUTINE PrintArray(a, n)
  INTEGER(KIND = 2), DIMENSION (n) :: a
  INTEGER :: i

  DO i = 1, n
    PRINT *, a(i)
  END DO  
END SUBROUTINE PrintArray
