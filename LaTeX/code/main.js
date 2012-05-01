var curve = require("./curve.js"),
    elgamel = require("./elgamel.js"),
    point = require("./point.js");

var curve = curve(14, 19, 3623),
    s_pt  = point(6, 730);

var alice = elgamel(curve, s_pt, 12),
    alice_pub = alice.computePublicKey();

var bob = elgamel(curve, s_pt, 32),
    bob_pub = bob.computePublicKey(),
    message = point(2149, 196);

bob.encrypt(message, alice_pub, function(ciphertext){
    var plaintext = alice.decrypt(ciphertext);
    console.log(plaintext);
    console.log(message);
});

