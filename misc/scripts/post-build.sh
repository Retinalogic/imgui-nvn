#!/bin/bash
set -e

OUT_NSO=${OUT}/${BINARY_NAME}
OUT_NPDM=${OUT}/main.npdm
RENDERER_NSO=${OUT}/subsdk8

# Clear older build.
rm -rf ${OUT}

# Create out directory.
mkdir ${OUT}

# Copy build into out
mv ${NAME}.nso ${OUT_NSO}
mv ${NAME}.npdm ${OUT_NPDM}
cp imguirenderer.nso ${RENDERER_NSO}

# Copy ELF to user path if defined.
if [ ! -z $ELF_EXTRACT ]; then
    cp "$NAME.elf" "$ELF_EXTRACT"
fi
