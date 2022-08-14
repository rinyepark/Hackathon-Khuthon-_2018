#!/usr/bin/python
from mpl_toolkits.basemap import Basemap
import matplotlib.pyplot as plt
import numpy as np
import xlrd

lats,lons,types = [],[],[]

filename = '홍익대학교.xlsx'

workbook = xlrd.open_workbook(filename)
sheet_names = workbook.sheet_names()
sheet = workbook.sheet_by_name(sheet_names[0])
sheet = workbook.sheet_by_index(0)
row = sheet.row(0)

from xlrd.sheet import ctype_text

for idx, cell_obj in enumerate(row):
    num_cols = sheet.ncols
    for row_idx in range(1, sheet.nrows):
        types.append(str(sheet.cell(row_idx,2))[6])
        lons.append(float(str(sheet.cell(row_idx,5))[7:]))
        lats.append(float(str(sheet.cell(row_idx,6))[7:]))
            
# the asos_stations file can be found here: 
# https://engineersportal.com/s/asos_stations.csv


# How much to zoom from coordinates (in degrees)
zoom_scale = 0.001

# Setup the bounding box for the zoom and bounds of the map
bbox = [np.min(lats)-zoom_scale,np.max(lats)+zoom_scale,\
        np.min(lons)-zoom_scale,np.max(lons)+zoom_scale]

plt.figure(figsize=(12,6))
# Define the projection, scale, the corners of the map, and the resolution.
m = Basemap(projection='merc',llcrnrlat=bbox[0],urcrnrlat=bbox[1],\
            llcrnrlon=bbox[2],urcrnrlon=bbox[3],lat_ts=10,resolution='i',\
            area_thresh = 0)

# Draw coastlines and fill continents and water with color
m.drawcoastlines()
m.fillcontinents(color='lightgray',lake_color='dodgerblue')

# draw parallels, meridians, and color boundaries
m.drawparallels(np.arange(bbox[0],bbox[1],(bbox[1]-bbox[0])/5),labels=[1,0,0,0])
m.drawmeridians(np.arange(bbox[2],bbox[3],(bbox[3]-bbox[2])/5),labels=[0,0,0,1],rotation=45)
m.drawmapboundary(fill_color='dodgerblue')

# build and plot coordinates onto map
for i in range(len(types)):

    x,y = m(lons[i],lats[i])

    if types[i] == "Q":

        m.plot(x,y,'r.',markersize=2)

    elif types[i] == "S":

        m.plot(x,y,'gp',markersize=2)

    elif types[i] == "R":

        m.plot(x,y,'bs',markersize=2)

    elif types[i] == "L":

        m.plot(x,y,'kX',markersize=2)

    elif types[i] == "F":

        m.plot(x,y,'cD',markersize=2)

    elif types[i] == "D":

        m.plot(x,y,'w^',markersize=2)

    else:

        m.plot(x,y,'y*',markersize=2)


plt.title("Hongik Univ")
plt.savefig('Hongik.png', format='png', dpi=500)
plt.show()


