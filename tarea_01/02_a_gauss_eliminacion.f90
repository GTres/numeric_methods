program op_matriz
    implicit none
    integer, parameter:: n=3
    integer i,j
    real*4 a(n,n), b(n), x(n)

    !-------------------------------------------
    ! Llenar la matriz a y el vector b
    data (a(1,i), i=1,3) /  4.0, -2.0,  1.0 /
    data (a(2,i), i=1,3) / -2.0,  4.0, -2.0 /
    data (a(3,i), i=1,3) /  1.0, -2.0,  4.0 / 

    data (b(i), i=1,3)   / 11.0,-16.0,17.0 /
    !-------------------------------------------


    !-------------------------------------------
    ! Mostrar la matriz
    print*, "Matriz a"
    do i = 1, n
        print*,(a(i,j),j=1,n)
    end do

    ! Mostrar vector b
    print*,"Vector b"
    do i=1,n
        print*,b(i)
    end do
    !-------------------------------------------



    call gauss_elimination(a,b,x,n)
    
    !-------------------------------------------
    ! Mostrar resultado
    print*, "Resultado "
    do i=1,n
        print*, x(i)
    end do
    do i=1,n 
        print*,(a(i,j),j=1,n)
    end do
    !-------------------------------------------
end program op_matriz             




subroutine gauss_elimination(a,b,x,n)
    real*4 a(n,n), b(n), x(n), l
    integer n, i, j, k



    !-------------------------------------------
    ! Eliminar 
    do k = 1, n-1
        do i = k+1, n
            l= a(i,k) / a(k,k)
            a(i,k) = l
            b(i) = b(i) - l* b(k)
            do j = k+1, n
                a(i,j) = a(i,j) - l* a(k,j)
            end do
        end do
    end do



    !-------------------------------------------
    ! sustituir
    x(n) = b(n) / a(n,n)
    do i = n-1, 1, -1
        x(i) = b(i)
        do j = n, i+1, -1
            x(i) = x(i) - a(i,j) * x(j)
        end do
        x(i) = x(i) / a(i,i)
    end do
    return
end subroutine gauss_elimination



