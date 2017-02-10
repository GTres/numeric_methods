program main
!====================================================
!  Solve tridiagonal matrix using thomas algorithm
!=====================================================
implicit none
integer, parameter :: n=7
real*4 a(n,3), b(n), x(n)
integer i,j,k 
!----------------------------------------
! Matrix a
!-----------------------------------------
data (a(1,j),j=1,3) / 0.0, -2.25, 1.0 /
data (a(2,j),j=1,3) / 1.0, -2.25, 1.0 /
data (a(3,j),j=1,3) / 1.0, -2.25, 1.0 /
data (a(4,j),j=1,3) / 1.0, -2.25, 1.0 /
data (a(5, j),j=1,3) / 1.0, -2.25, 1.0 /
data (a(6, j),j=1,3) / 1.0, -2.25, 1.0 /
data (a(7,j),j=1,3)  / 1.0, -2.25, 0.0 /
!----------------------------------------
! Vector b
!-----------------------------------------
data (b(i),i=1,7) / 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -100.0 /
    print*,"Matriz a"
    do i=1,n
        print*,(a(i,j),j=1,3)
    end do

    print*,"Vector b"
    do i=1,n
        print*,b(i)
    end do

    call thomas (n,a,b,x)
    print*,''
    print*,''
    print*,"Resultados"
    print*,"Matriz a'"
    do i=1,n
        print*,(a(i,j),j=1,3)
    end do

    print*,''

    print*,"Vector b'"
    do i=1,n
        print*,b(i)
    end do
     
    print*,''

    print*,"Vector x"
    do i=1,n
        print*,x(i)
    end do
end program main
!------------------------------------------------
! Soubroutine Thomas algorithm
!------------------------------------------------
subroutine thomas (n,a,b,x)
     real*4 a(n,3), b(n), x(n)
!----forward elimination---------
     do i=2,n
          em=a(i,1)/a(i-1,2)
          a(i,1)=em
          a(i,2)=a(i,2) -em*a(i-1,3)
          b(i)=b(i) -a(i,1)*b(i-1)
     end do
!----back subscitution
     x(n)=b(n)/a(n,2)
     do i=n-1,1,-1
          x(i)= (b(i) -a(i,3)*x(i+1))/a(i,2)
     end do
     return
end subroutine thomas
