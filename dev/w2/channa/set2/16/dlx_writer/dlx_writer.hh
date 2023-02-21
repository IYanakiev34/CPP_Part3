#ifndef dlx_writer_hh_defd
#define dlx_writer_hh_defd

#include "../dancing_links.hh"

// We neither want to keep the offset map around nor want to pass it as argument.
// So we have this wrapper class, just to output a DLX.
class DLX_Writer
{
    
    typedef std::map<DLX::ColumnHeaderNode const *, std::size_t> offset_map_t;
    
    offset_map_t d_column_offsets; // The reason for this class.
    DLX const &d_dlx; // The object we're outputting.
    
public:
    
    DLX_Writer(DLX const &dlx);
    friend std::ostream &operator<<(std::ostream &out, DLX_Writer &writer);
    
private:
    
    std::ostream &write_column_headers(std::ostream &out);
    std::ostream &write_rows(std::ostream &out);
    // Only prints if first_node is actually the first node i.e. < prev node.
    std::ostream &write_row(std::ostream &out, DLX::Node const *first_node);
    
};


inline DLX_Writer::DLX_Writer(DLX const &dlx)
    : d_dlx(dlx)
{}


#endif //dlx_writer_hh_defd
