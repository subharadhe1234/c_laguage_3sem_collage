import pandas as pd
import matplotlib.pyplot as plt
import io
from PIL import Image
# thid function help file to image
def pltToImg(plt):
    fig=plt.gcf()
    buf=io.BytesIO()
    fig.savefig(buf)
    buf.seek(0)
    img=Image.open(buf)
    return img

df=pd.read_csv('file_o.csv')
print(df)
plt.plot(df["input"],df["compation"])
img=pltToImg(plt)
# same imga
img.save("image.png")
plt.show()