!A simple module for producing escape codes for ANSI colors in terminal
!output.  See the example program below for an example of usage.  Fortran 2003
!compliant.

!Save as `ansi.f90` and compile with `gfortran -std=f2003 -o ansi ansi.f90`.

!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ {: lang=fortran }
module ansi_colors
  implicit none

  character(len=1), parameter :: c_esc = achar(27)
  character(len=2), parameter :: c_start = c_esc // '['
  character(len=1), parameter :: c_end = 'm'
  character(len=*), parameter :: c_black = '30'
  character(len=*), parameter :: c_red = '31'
  character(len=*), parameter :: c_green = '32'
  character(len=*), parameter :: c_yellow = '33'
  character(len=*), parameter :: c_blue = '34'
  character(len=*), parameter :: c_magenta = '35'
  character(len=*), parameter :: c_cyan = '36'
  character(len=*), parameter :: c_white = '37'
  character(len=*), parameter :: c_clear = c_start // '0' // c_end

contains

  function color(str, code) result(out)
    character(len=*), intent(in) :: str
    character(len=*), intent(in) :: code
    character(len=:), allocatable :: out
    out = c_start // code // c_end // str // c_clear
  end function color

end module ansi_colors
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

!Usage example:

!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ {: lang=fortran }
program ansi
  use ansi_colors
  implicit none

  character(len=*), parameter :: endl = new_line('a')

  print '(a)', &
       color('Red',     c_red)     // endl // &
       color('Green',   c_green)   // endl // &
       color('Yellow',  c_yellow)  // endl // &
       color('Blue',    c_blue)    // endl // &
       color('Magenta', c_magenta) // endl // &
       color('Cyan',    c_cyan)    // endl // &
       color('White',   c_white)
end program ansi
!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

