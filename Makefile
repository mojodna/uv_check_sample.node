binding.node: build binding.cc
	node-gyp build

build:
	node-gyp configure

clean:
	node-gyp clean

.PHONY: clean
