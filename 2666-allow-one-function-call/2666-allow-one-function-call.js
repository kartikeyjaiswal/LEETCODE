function once(fn) {
    let called = false;
    return function (...args) {
        if (called) return undefined;
        called = true;
        return fn(...args);
    };
}