const crypto = require('crypto');

function sha1Hash(input) {
  const sha1 = crypto.createHash('sha1');
  sha1.update(input);
  return sha1.digest('hex');
}

function bytesToHex(bytes) {
  const hexDigits = '0123456789ABCDEF';
  let hex = '';
  for (let i = 0; i < bytes.length; i++) {
    const byte = bytes[i];
    hex += hexDigits[(byte >>> 4) & 0x0F] + hexDigits[byte & 0x0F];
  }
  return hex;
}

console.log('Message digest object info:');
console.log('Algorithm = ' + crypto.getHashes().find((hash) => hash === 'sha1'));
console.log('Provider = Node.js crypto module');
console.log('ToString = [object Hash]\n');

const input1 = "";
const output1 = sha1Hash(input1).toUpperCase();
console.log(`SHA-1("${input1}") = ${output1}`);

const input2 = 'abc';
const output2 = sha1Hash(input2).toUpperCase();
console.log(`SHA-1("${input2}") = ${output2}`);

const input3 = 'abcdefghijklmnopqrstuvwxyz';
const output3 = sha1Hash(input3).toUpperCase();
console.log(`SHA-1("${input3}") = ${output3}`);
