const crypto = require('crypto');

function computeMD5Hash(plainText) {
  const hash = crypto.createHash('md5');
  hash.update(plainText);
  return hash.digest('hex');
}

function generateMD5HashForInput() {
  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });

  rl.question('Enter the plain text: ', (plainText) => {
    const md5Hash = computeMD5Hash(plainText);
    console.log(`MD5 Hash of '${plainText}': 0x${md5Hash}`);
    rl.close();
  });
}

// Call the function to generate MD5 hash for user-defined input
generateMD5HashForInput();
