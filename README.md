# color-text
Atari Lynx programming tutorial working with text

## Requirements

cc65

http://cc65.github.io/cc65

## Environment

export CC65_HOME={cc65 home dir}


## Build

make all

load the resultant color.lyx file into your emulator

## lynx-160-102-16 driver

Details can be found in the TGI library programmer’s reference.

### Lifecycle
```
tgi_install 
tgi_uninstall 
tgi_init 
tgi_done
```

### Typography

```
tgi_outtext 
tgi_outtextxy
```

### Screen management

```
tgi_clear 
tgi_setdrawpage 
tgi_setviewpage 
tgi_getpagecount 
tgi_getxres 
tgi_getmaxx 
tgi_getyres 
tgi_getmaxy 
tgi_getaspectratio 
tgi_setaspectratio
```

### Colors

```
tgi_getcolorcount 
tgi_getmaxcolor 
tgi_setcolor 
tgi_getcolor 
tgi_setpalette 
tgi_getpalette 
tgi_getdefpalette
```

### Drawing

```
tgi_getpixel 
tgi_setpixel 
tgi_gotoxy 
tgi_line 
tgi_lineto 
tgi_circle 
tgi_ellipse 
tgi_arc 
tgi_pieslice 
tgi_bar
```

### Miscellaneous

```
tgi_error 
tgi_geterrormsg 
tgi_ioctl
```

### Lynx specific

```
tgi_sprite 
tgi_flip 
tgi_setbgcolor 
tgi_setframerate 
tgi_busy 
tgi_updatedisplay 
tgi_setcollisiondetection
```

