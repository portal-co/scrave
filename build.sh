cd $(dirname  $0)
set -e
sh ./packages/glyph/build.sh
cargo run --release -p scrave-glyph-image-generator -- $(pwd)/images