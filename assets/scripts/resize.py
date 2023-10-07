from PIL import Image

def resize_image(input_path, new_width, new_height):
    try:
        img = Image.open(input_path)

        img = img.resize((new_width, new_height), Image.ANTIALIAS)

        img.save(input_path)

        print(f"Image resized and saved to {input_path}")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    input_path = "torpedo.png"  

    resize_image(input_path, 66, 64)
