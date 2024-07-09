import { exec } from "child_process";
import { join } from "path";
import { mainFolder, testingFolder } from "./constants";

export function runAssembler(fileName: string) {
  const command = `${join(mainFolder, "bin/assembler")} ${join(
    testingFolder,
    fileName
  )}`;
  console.log("====================================");
  console.log("Running command: ", command);
  console.log("====================================");
  exec(command, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error: ${error.message}`);
      return;
    }
    if (stderr) {
      console.error(`Stderr: ${stderr}`);
      return;
    }
    console.log(`Output: ${stdout}`);
  });
}
