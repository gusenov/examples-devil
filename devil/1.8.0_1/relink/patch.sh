rm -f libIL.dylib
rm -f libILU.dylib
rm -f libILUT.dylib

cp ../lib/libIL.dylib libIL.dylib
cp ../lib/libILU.dylib libILU.dylib
cp ../lib/libILUT.dylib libILUT.dylib

chmod 644 libIL.dylib
chmod 644 libILU.dylib
chmod 644 libILUT.dylib

install_name_tool -id @rpath/libIL.dylib libIL.dylib
install_name_tool -change /usr/local/opt/libpng/lib/libpng16.16.dylib @rpath/libpng16.16.dylib libIL.dylib
install_name_tool -change /usr/local/opt/jpeg/lib/libjpeg.9.dylib @rpath/libjpeg.9.dylib libIL.dylib
install_name_tool -change /usr/local/opt/libtiff/lib/libtiff.5.dylib @rpath/libtiff.5.dylib libIL.dylib
install_name_tool -change /usr/local/opt/jasper/lib/libjasper.4.dylib @rpath/libjasper.4.dylib libIL.dylib
install_name_tool -change /usr/local/opt/little-cms2/lib/liblcms2.2.dylib @rpath/liblcms2.2.dylib libIL.dylib

install_name_tool -id @rpath/libILU.dylib libILU.dylib
install_name_tool -change @loader_path/libIL.dylib @rpath/libIL.dylib libILU.dylib
install_name_tool -change /usr/local/opt/libpng/lib/libpng16.16.dylib @rpath/libpng16.16.dylib libILU.dylib
install_name_tool -change /usr/local/opt/jpeg/lib/libjpeg.9.dylib @rpath/libjpeg.9.dylib libILU.dylib
install_name_tool -change /usr/local/opt/libtiff/lib/libtiff.5.dylib @rpath/libtiff.5.dylib libILU.dylib
install_name_tool -change /usr/local/opt/jasper/lib/libjasper.4.dylib @rpath/libjasper.4.dylib libILU.dylib
install_name_tool -change /usr/local/opt/little-cms2/lib/liblcms2.2.dylib @rpath/liblcms2.2.dylib libILU.dylib

install_name_tool -id @rpath/libILUT.dylib libILUT.dylib
install_name_tool -change @loader_path/libILU.dylib @rpath/libILU.dylib libILUT.dylib
install_name_tool -change @loader_path/libIL.dylib @rpath/libIL.dylib libILUT.dylib
install_name_tool -change /usr/local/opt/libpng/lib/libpng16.16.dylib @rpath/libpng16.16.dylib libILUT.dylib
install_name_tool -change /usr/local/opt/jpeg/lib/libjpeg.9.dylib @rpath/libjpeg.9.dylib libILUT.dylib
install_name_tool -change /usr/local/opt/libtiff/lib/libtiff.5.dylib @rpath/libtiff.5.dylib libILUT.dylib
install_name_tool -change /usr/local/opt/jasper/lib/libjasper.4.dylib @rpath/libjasper.4.dylib libILUT.dylib
install_name_tool -change /usr/local/opt/little-cms2/lib/liblcms2.2.dylib @rpath/liblcms2.2.dylib libILUT.dylib

otool -L libIL.dylib
otool -L libILU.dylib
otool -L libILUT.dylib

rm -f libjasper.4.dylib 
rm -f libjpeg.9.dylib 
rm -f liblcms2.2.dylib 
rm -f libpng16.16.dylib 
rm -f libtiff.5.dylib

cp /usr/local/opt/jasper/lib/libjasper.4.dylib libjasper.4.dylib
cp /usr/local/opt/jpeg/lib/libjpeg.9.dylib libjpeg.9.dylib
cp /usr/local/opt/little-cms2/lib/liblcms2.2.dylib liblcms2.2.dylib
cp /usr/local/opt/libpng/lib/libpng16.16.dylib libpng16.16.dylib
cp /usr/local/opt/libtiff/lib/libtiff.5.dylib libtiff.5.dylib

chmod 644 libjasper.4.dylib 
chmod 644 libjpeg.9.dylib 
chmod 644 liblcms2.2.dylib 
chmod 644 libpng16.16.dylib 
chmod 644 libtiff.5.dylib

install_name_tool -id @rpath/libjasper.4.dylib libjasper.4.dylib
install_name_tool -change /usr/local/opt/jpeg/lib/libjpeg.9.dylib @rpath/libjpeg.9.dylib libjasper.4.dylib

install_name_tool -id @rpath/libjpeg.9.dylib libjpeg.9.dylib
 
install_name_tool -id @rpath/liblcms2.2.dylib liblcms2.2.dylib

install_name_tool -id @rpath/libpng16.16.dylib libpng16.16.dylib

install_name_tool -id @rpath/libtiff.5.dylib libtiff.5.dylib
install_name_tool -change /usr/local/opt/jpeg/lib/libjpeg.9.dylib @rpath/libjpeg.9.dylib libtiff.5.dylib

otool -L libjasper.4.dylib 
otool -L libjpeg.9.dylib 
otool -L liblcms2.2.dylib 
otool -L libpng16.16.dylib 
otool -L libtiff.5.dylib
