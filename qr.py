import qrcode

# Define the data to be encoded as a QR code
data = '''https://www.facebook.com/fijichess/'''

# Create a QR code instance
qr = qrcode.QRCode(version=1, box_size=10, border=2)

# Add the data to the QR code
qr.add_data(data)

# Generate the QR code image
qr.make(fit=True)
img = qr.make_image(fill_color="black", back_color="white")

# Save the image as a PNG file
img.save("qrcode.png")
