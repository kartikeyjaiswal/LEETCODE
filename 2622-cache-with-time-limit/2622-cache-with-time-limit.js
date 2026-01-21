var TimeLimitedCache = function() {
    this.cache = new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration
 * @return {boolean}
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();
    const exists =
        this.cache.has(key) && this.cache.get(key).expiry > now;

    this.cache.set(key, {
        value: value,
        expiry: now + duration
    });

    return exists;
};

/** 
 * @param {number} key
 * @return {number}
 */
TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) return -1;

    const entry = this.cache.get(key);
    if (entry.expiry <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return entry.value;
};

/** 
 * @return {number}
 */
TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let count = 0;

    for (const [key, entry] of this.cache) {
        if (entry.expiry > now) {
            count++;
        } else {
            this.cache.delete(key);
        }
    }

    return count;
};