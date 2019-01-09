# reductive-broken-compilation-example

in-lib works fine

in-source fails in runtime with 
```
Uncaught TypeError: f.apply is not a function
    at app (curry.js:12)
    at curry_2 (curry.js:131)
    at Module._2 (curry.js:143)
    at Module.element (ReasonReact.js:538)
    at Module../src/index.re (index.re:14)
    at __webpack_require__ (bootstrap:782)
    at fn (bootstrap:150)
    at Object.0 (thunkedStore.re:58)
    at __webpack_require__ (bootstrap:782)
    at checkDeferredModules (bootstrap:45)
    at Array.webpackJsonpCallback [as push] (bootstrap:32)
    at main.chunk.js:1
```

patched-in-source works 

more info: https://github.com/reasonml-community/reductive/issues/39
