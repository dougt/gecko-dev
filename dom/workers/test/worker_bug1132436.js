onmessage = function(e) {
  var req = indexedDB.open("foobar", 1);

  req.onupgradeneeded = function (e) {
    e.target.result.createObjectStore("store");
  };

  req.onsuccess = function (e) {
    Promise.resolve().then(function(val) {
      var idb = e.target.result;
      var txn = idb.transaction(["store"], 'readwrite');
      var req = txn.objectStore("store").get("store");
      req.onsuccess = function (e) {
        var txn = idb.transaction(["store"], 'readonly');
        postMessage('good so far.');
      }
    });
  };
}

