from PIL import Image

size = 64

img = Image.open("a.png")

for i in range(9):
    frame = img.crop((i*64, 0, (i+1)*64, 64))
    frame.save(f"{i}.png")