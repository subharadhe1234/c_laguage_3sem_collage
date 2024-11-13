import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
df=pd.read_csv('file.csv', names=["X","Y","id"])
df.head(10)
sns.scatterplot(x=df['X'],y=df['Y'],hue=df['id'])