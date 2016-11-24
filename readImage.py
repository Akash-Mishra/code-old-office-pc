from PIL import Image
from pylab import *
import os

# for infile in filelist:
# 	outfile = os.path.splittext(infile)[0] + ".jpg"
# 	if infile != outfile:
# 		try:
# 			Image.open(infile).save(outfile)
# 		except IOError:
# 			print "cannot convert", infile
pil_im = Image.open('/home/akash.mishra/Music/learn/IPPython/desktop.png').convert('L')
imshow(pil_im)