import qrcode

# Define the data to be encoded as a QR code
data = '''https://invite.viber.com/?g2=AQA7u0eXm8JqIFDEeUCGujpxr%2B9QFTWWrpu%2FZMVOLN54beWf%2BjSMeSWNXE7Jcash'''

# Create a QR code instance
qr = qrcode.QRCode(version=1, box_size=10, border=5)

# Add the data to the QR code
qr.add_data(data)

# Generate the QR code image
qr.make(fit=True)
img = qr.make_image(fill_color="black", back_color="white")

# Save the image as a PNG file
img.save("qrcode.png")
