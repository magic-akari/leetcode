const { join } = require("path");
const { writeFileSync } = require("fs");

const lodashEsPath = require.resolve("lodash-es");

const packageJsonPath = join(lodashEsPath, "../package.json");

const packageJson = require(packageJsonPath);

packageJson.type = "module";

writeFileSync(packageJsonPath, JSON.stringify(packageJson, null, 2));

const info = [
    "",
    `[info] ${__filename} :`,
    `This script add "type": "module" into ${packageJsonPath}`,
    `See more: https://github.com/lodash/lodash/pull/4292`,
    "",
];

info.forEach((i) => console.log(i));
