var fs = require('fs');

fs.createReadStream('./lib/ICT3K5_6240DLL.dll').pipe(fs.createWriteStream('./build/Release/ICT3K5_6240DLL.dll'));

fs.createReadStream('./lib/PrtclRS8.dll').pipe(fs.createWriteStream('./build/Release/PrtclRS8.dll'));

fs.createReadStream('./lib/CollectLogEx.dll').pipe(fs.createWriteStream('./build/Release/CollectLogEx.dll'));