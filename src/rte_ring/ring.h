struct rte_ring {

    TAILQ_ENTRY(rte_ring) next;     
char name[RTE_MEMZONE_NAMESIZE];      
int flags;                         
const struct rte_memzone *memzone;



struct prod {
uint32_t watermark;        
uint32_t sp_enqueue;       
uint32_t size;             
uint32_t mask;             

volatile uint32_t head;    
volatile uint32_t tail;    
    } prod __rte_cache_aligned;  


struct cons {
uint32_t sc_dequeue;       
uint32_t size;             
uint32_t mask;            

volatile uint32_t head;    
volatile uint32_t tail;    
#ifdef RTE_RING_SPLIT_PROD_CONS  
    } cons __rte_cache_aligned;  
#else
    } cons;  
#endif

#ifdef RTE_LIBRTE_RING_DEBUG  
struct rte_ring_debug_stats stats[RTE_MAX_LCORE];
#endif

void *ring[] __rte_cache_aligned;     
};