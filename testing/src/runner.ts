import { exec } from "child_process";
import { join } from "path";
import { mainFolder, testingFolder } from "./constants";

export function runAssembler(
  filePath: string
): Promise<{ error: number | undefined }> {
  const command = `${join(mainFolder, "bin/assembler")} ${filePath}`;
  console.log("====================================");
  console.log("Running command: ", command);
  console.log("====================================");
  return new Promise((resolve) => {
    exec(command, (error, stdout, stderr) => {
      if (error) {
        console.error(`Error: ${JSON.stringify(error)}`);
        return resolve({ error: error.code });
      }
      if (stderr) {
        console.error(`Stderr: ${stderr}`);
        // return resolve({ error: stderr.code });
      }
      return resolve({ error: undefined });
    });
  });
}
