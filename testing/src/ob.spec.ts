import { readFile } from "fs/promises";

describe("testing object builder", () => {
  test.each(["ps"])(
    "testing object builder on %s",
    async (fileName: string) => {
      // compare macro.am in examples with macro.am in expectations
      const generatedObjectFile = await readFile(
        `./examples/${fileName}.ob`,
        "utf-8"
      );
      const expectedObjectFile = await readFile(
        `./expectations/${fileName}.ob`,
        "utf-8"
      );
      expect(generatedObjectFile).toBe(expectedObjectFile);
    }
  );
});
