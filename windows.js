var binding = require('./Debug/check.node');

binding.registerCheck();
setTimeout(binding.unregisterCheck, 5000);
