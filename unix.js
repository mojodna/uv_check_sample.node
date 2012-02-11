var binding = require('./out/Release/check.node');

binding.registerCheck();
setTimeout(binding.unregisterCheck, 5000);
