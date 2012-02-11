This add-on demonstrates inconsistent `uv_check_*` behavior between the unix and
windows implementations.

## OS X and Linux

Building:

```bash
npm install -g node-gyp
make
```

Running:

```bash
$ node unix.js
registering check
running check
<pause>
running check
running check
unregistering check
```

## Windows

Building (from Visual Studio Command Prompt):

```bash
msbuild
```

Running:

```bash
>node windows.js
registering check
<pause>
running check
running check (sometimes)
unregistering check
```
