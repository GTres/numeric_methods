program main
    implicit none
    integer, parameter :: n=3
    real*4 a(n,n), c(n,n)
    integer i,j
    ! Llenar la  matrix a
    data (a(1,i), i=1,3) /  80.0, -20.0,  -20.0 /
    data (a(2,i), i=1,3) / -20.0,  40.0,  -20.0 /
    data (a(3,i), i=1,3) / -20.0, -20.0, 130.0 / 


    call inversa(a,c,n)

    print*,('-',i=1,79)
    print '(30X,"Inversa de una Matriz")'
    print*,('-',i=1,79)
    print*,''  

    !-------------------------------------------
    ! Mostrar la matriz a
    print*, "Matriz a"
    print '(/3f12.6/)',((a(i,j),i=1,n),j=1,n)
    !-------------------------------------------


    print*,'' 
    print*,''  
    
    !-------------------------------------------
    ! Mostrar la matriz inversa de a
    print*, "Inversa de a"
    print '(/3f12.6/)',((c(i,j),i=1,n),j=1,n)
    !-------------------------------------------
end program main

subroutine inversa(a,c,n)
implicit none 
integer n
real*4 a(n,n), c(n,n)
real*4 L(n,n), U(n,n), b(n), d(n), x(n)
real*4 coeff
integer i, j, k

L=0.0
U=0.0
b=0.0

do k=1, n-1
    do i=k+1,n
        coeff=a(i,k)/a(k,k)
        L(i,k) = coeff
        do j=k+1,n
            a(i,j) = a(i,j)-coeff*a(k,j)
        end do
    end do
end do

do i=1,n
    L(i,i) = 1.0
end do

do j=1,n
    do i=1,j
        U(i,j) = a(i,j)
    end do
end do

do k=1,n
    b(k)=1.0
    d(1) = b(1)

    do i=2,n
        d(i)=b(i)
        do j=1,i-1
            d(i) = d(i) - L(i,j)*d(j)
        end do
    end do

    x(n)=d(n)/U(n,n)
    do i = n-1,1,-1
        x(i) = d(i)
        do j=n,i+1,-1
            x(i)=x(i)-U(i,j)*x(j)
        end do
        x(i) = x(i)/u(i,i)
    end do
    
    do i=1,n
        c(i,k) = x(i)
    end do
    b(k)=0.0
end do
end subroutine inversa
