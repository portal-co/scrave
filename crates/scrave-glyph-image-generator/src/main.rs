use image::{DynamicImage, GenericImage, ImageBuffer, ImageError, Rgb, RgbImage};

fn main() -> Result<(), ImageError> {
    let mut args = std::env::args();
    args.next();
    let out = args.next().unwrap();
    for a in 0u8..=255u8 {
        let mut bool_buf = [false; 25];
        portal_solutions_scrave_glyph::glyph(a, &mut bool_buf);
        let mut buffer = RgbImage::from_fn(80, 80, |x,y|{
            let (x,y) = (x >> 4,y >> 4);
            let a = bool_buf[(y * 5 + x) as usize];
            let a = if a{0}else{255};
            Rgb([a;3])
        });
        let mut buffer = DynamicImage::ImageRgb8(buffer);
        buffer.save(&format!("{out}/{a:x}.png"))?;
    }
    Ok(())
}
