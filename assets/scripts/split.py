from PIL import Image

size = 64

img = Image.open("torpedo.png")

for i in range(3):
    frame = img.crop((i*22, 0, (i+1)*22, 64))
    frame.save(f"{i}.png")