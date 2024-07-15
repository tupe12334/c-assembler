import { glob } from "glob";
import { runAssembler } from "./runner";
import { rm } from "fs/promises";

async function main() {
  /* delete all files that are not .as */
  const notAsFiles = await glob("./examples/**.**", {
    ignore: "./examples/**.as",
  });
  for (const file of notAsFiles) {
    await rm(file);
  }
  const asFiles = await glob("./examples/**.as");
  for (const file of asFiles) {
    const fileWithoutExt = file.substring(0, file.length - 3);
    runAssembler(fileWithoutExt);
  }
}

if (module === require.main) {
  (async () => {
    main();
  })();
}
