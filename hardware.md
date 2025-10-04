What I was looking for

- some kind of display
- service that cuts steel plates (for keyboard plate)
- service that prints PCBs
- supplier of the electronic components needed for the PCB


## Monitor

My requirements for the monitor
- 7 inch
- preferably IPS
- SPI
- 3.3V logic

Found this one on buydisplay that seems to fill all requirements
([7 inch display 1024x600 IPS TFT SPI](https://www.buydisplay.com/7-inch-1024x600-ips-tft-touch-display-module-with-i2c-spi-for-arduino))

## Plate + PCB

### Plate

Ponoko seems like a good service for laser cutting the acrylic plate

I generated a layout using ([KLE](https://www.keyboard-layout-editor.com/#/)) which I saved as kle_qabkb_v1.json.
This was then input into https://kbplate.ai03.com/ to generate a DXF file for laser cutting/CAD work.

I then realized that even with a plate and pcb I would have no case to mount it in, and to even be able to mount it into a case I would need holes for screws.

### PCB

I have had JLCPCB recommended to me before so I decided that I will source my PCBs from there, since they require a gerber file I got started with creating the schematic in KiCad so I could move on to the PCB editor after that.


