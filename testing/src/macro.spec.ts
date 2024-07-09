import { readFile } from "fs/promises";

describe("testing macro runner", () => {
  test.each(["macro", "end_line"])(
    "testing macro runner %s",
    async (fileName: string) => {
      // compare macro.am in examples with macro.am in expectations
      const generatedMacroAm = await readFile(
        `./examples/${fileName}.am`,
        "utf-8"
      );
      const expectedMacroAm = await readFile(
        `./expectations/${fileName}.am`,
        "utf-8"
      );
      expect(generatedMacroAm).toBe(expectedMacroAm);
    }
  );
});
